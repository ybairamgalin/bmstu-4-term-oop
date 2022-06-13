#ifndef LAB_03_BASECOMMAND_H
#define LAB_03_BASECOMMAND_H


class BaseCommand
{
public:
    virtual ~BaseCommand() = default;
    virtual void exec() = 0;
};


#endif //LAB_03_BASECOMMAND_H
