//
// Created by virko on 11/19/2021.
//

#ifndef COMMAND_LINE_TOOL_DBL_ARGUMENT_H
#define COMMAND_LINE_TOOL_DBL_ARGUMENT_H

#include "argument.h"

class dbl_argument : public argument{
public:
    dbl_argument(std::string id, double value);
    double value() const;

private:
    double m_value;

};


#endif //COMMAND_LINE_TOOL_DBL_ARGUMENT_H
