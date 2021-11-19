//
// Created by virko on 11/19/2021.
//

#ifndef COMMAND_LINE_TOOL_STR_ARGUMENT_PARSER_H
#define COMMAND_LINE_TOOL_STR_ARGUMENT_PARSER_H


#include "argument_parser.h"

class str_argument_parser: public argument_parser {
public:
    std::unique_ptr<argument> parse(std::string id, const char* string) const override;
};

#endif //COMMAND_LINE_TOOL_STR_ARGUMENT_PARSER_H
