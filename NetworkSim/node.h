#ifndef NODE_H
#define NODE_H

#include "stdafx.h"

class node
{
public:
    node();
    bool is_source();
    void set_source(bool new_source);

private:
    bool source;
};

#endif // NODE_H
