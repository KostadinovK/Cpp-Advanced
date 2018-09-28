#pragma once

#include <string>

namespace SoftUni{
    class Resource{
    private:
        std::string id;
        ResourceType type;
        std::string link;
    public:
        Resource(){}
        Resource(std::string id, ResourceType type, std::string link) : id(id),type(type),link(link){}

        std::string getId() const {
            return this->id;
        }

        ResourceType getType() const {
            return this->type;
        }

        std::string getLink() const {
            return this->link;
        }

        bool operator< (const Resource& other) const {
            return stoi(this->id) < stoi(other.id);
        }


        friend std::istream& operator>>( std::istream& input, Resource& r) {
            std::string type;
            input >> r.id >> type >> r.link;
            if(type == "Demo"){
                r.type = ResourceType::DEMO;
            }else if(type == "Presentation"){
                r.type = ResourceType::PRESENTATION;
            }else{
                r.type = ResourceType::VIDEO;
            }
            return input;
        }

        friend std::ostream& operator<<( std::ostream& out, const Resource& r) {
            out << r.id <<" "<< r.type << " " << r.link;
            return out;
        }
    };


}
