#ifndef LAB_03_FACADE_H
#define LAB_03_FACADE_H

#include "../commands/basecommand.h"

class Facade
{
public:
    static void exec(BaseCommand &command);
};


#endif //LAB_03_FACADE_H
