#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace SoftUni{
    class Lecture{
    private:
        std::vector<Resource> resources;

        void sortResourcesById(){
            std::sort(resources.begin(),resources.end());
        }
    public:
        Lecture(){}
        Lecture(std::vector<Resource> resources): resources(resources){
            sortResourcesById();
        }

        std::vector<Resource> getResources() const {
            return this->resources;
        }

        std::vector<Resource>::const_iterator begin() const {
            return this->resources.begin();
        }

        std::vector<Resource>::const_iterator end() const {
            return this->resources.end();
        }

        Lecture& operator<< (const Resource& r){
            for(int i = 0;i < this->resources.size();i++){
                if(this->resources[i].getId() == r.getId()){
                    this->resources.erase(this->resources.begin() + i);
                    i--;
                }
            }

            this->resources.push_back(r);
            sortResourcesById();
            return *this;
        }

        int operator[] (ResourceType& type) {
            int res = 0;
            for(int i = 0;i < this->resources.size();i++){
                if(this->resources[i].getType() == type){
                    res++;
                }
            }
            return res;
        }

        friend std::vector<ResourceType>& operator<< (std::vector<ResourceType>& resources, const Lecture& l){

            for (const Resource& r : l) {
                bool ableToPush = true;
                for(int i = 0;i < resources.size();i++){
                    if(resources[i] == r.getType()){
                        ableToPush = false;
                        break;
                    }
                }
                if(ableToPush){
                    resources.push_back(r.getType());
                }
            }
            std::sort(resources.begin(),resources.end());
            return resources;
        }


    };



}
