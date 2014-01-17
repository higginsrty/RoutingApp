#ifndef LINK_H
#define LINK_H

class link
{
public:
    link();
    int parentNodeID;
    int childNodeID;
    bool parentEnabled();
    bool childEnabled();

};

#endif // LINK_H
