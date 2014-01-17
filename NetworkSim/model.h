#ifndef MODEL_H
#define MODEL_H

#include "stdafx.h"

class model
{
public:
    model();
    bool change_algorithm(std::string alg);
    int get_algorithm();
    int start_sim();
    int pause_sim();
    int resume_sim();
    int step_sim();
    int reset_sim();
};

#endif // MODEL_H
