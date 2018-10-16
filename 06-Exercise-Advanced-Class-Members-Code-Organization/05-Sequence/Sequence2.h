#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>

template<typename T, typename Generator>
class Sequence
{
    std::vector<T> elements;
    Generator generator;

public:
    class Iterator
    {
    public:
        int index;
        std::vector<T>& elements;

        Iterator(int index, std::vector<T>& elements) : index(index), elements(elements) {};

        void operator++()
        {
            this->index++;
        }

        T& operator*()
        {
            return this->elements[this->index];
        }

        bool operator!= ( const Iterator& other)
        {
            return this->index != other.index;
        }
    };

    void generateNext(int numToGenerate)
    {
        for (int i = 0; i < numToGenerate; i++)
        {
            T next = generator();
            elements.push_back(next);
        }
    }

    Iterator begin()
    {
        return Iterator(0, elements);
    }

    Iterator end()
    {
        return Iterator(elements.size()-1,elements);
    }
};

#endif // !SEQUENCE_H
