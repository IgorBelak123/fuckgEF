//
// Created by virko on 11/19/2021.
//

#ifndef COMMAND_LINE_TOOL_STR_ARGUMENT_H
#define COMMAND_LINE_TOOL_STR_ARGUMENT_H


#include "argument.h"

class str_argument : public argument {
public:
    str_argument(std::string id, std::string value);
    std::string value() const;
private:
    std::string m_value;

};


#endif //COMMAND_LINE_TOOL_STR_ARGUMENT_H
