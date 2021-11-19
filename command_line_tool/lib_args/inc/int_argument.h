//
// Created by virko on 11/19/2021.
//

#ifndef COMMAND_LINE_TOOL_INT_ARGUMENT_H
#define COMMAND_LINE_TOOL_INT_ARGUMENT_H


#include "argument.h"

class int_argument: public argument{
public:
    int_argument(std::string id, int value);
    int value() const;
private:
    int m_value;

};
#endif //COMMAND_LINE_TOOL_INT_ARGUMENT_H
