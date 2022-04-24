#ifndef __BASE_CONTAINER_H__
#define __BASE_CONTAINER_H__

class BaseContainer
{
public:
    virtual ~BaseContainer() = default;

    virtual bool isEmpty() const = 0;
    virtual void clear() = 0;

protected:
    size_t sz = 0;
};

#endif
