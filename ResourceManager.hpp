#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:

    ResourceManager()
    {
        resource = new Resource();
    }

    ResourceManager(const ResourceManager& other)
    {
        resource = new Resource(*other.resource); 
    }

    ResourceManager(ResourceManager&& other)
    {
        resource = other.resource;
        other.resource = nullptr;
    }

    ResourceManager& operator=(const ResourceManager& other)
    {
        delete resource;
        resource = new Resource(*other.resource);
        return *this;
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        delete resource;
        resource = other.resource;
        other.resource = nullptr;
        return *this;
    }

    ~ResourceManager()
    {
        if(resource != nullptr)
        {
            delete resource;
        }
    }

    double get()
    {
        return resource->get();
    }


private:
    Resource* resource;
};
