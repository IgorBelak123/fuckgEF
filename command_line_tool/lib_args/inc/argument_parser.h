//
// Created by virko on 11/19/2021.
//

#ifndef COMMAND_LINE_TOOL_ARGUMENT_PARSER_H
#define COMMAND_LINE_TOOL_ARGUMENT_PARSER_H


#include "sstream"
#include "memory"
#include "argument.h"

class argument_parser {
public:
// the id is passed because it's needed to create `argument`
    virtual std::unique_ptr<argument> parse(std::string id, const char* arg) const = 0;
    virtual ~argument_parser() = default;
};


#endif //COMMAND_LINE_TOOL_ARGUMENT_PARSER_H
