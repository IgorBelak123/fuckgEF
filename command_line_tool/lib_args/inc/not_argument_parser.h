//
// Created by virko on 11/21/2021.
//

#ifndef COMMAND_LINE_TOOL_NOT_ARGUMENT_PARSER_H
#define COMMAND_LINE_TOOL_NOT_ARGUMENT_PARSER_H
#include "argument_parser.h"

class not_argument_parser: public argument_parser {
public:
    [[nodiscard]] std::unique_ptr<argument> parsee(std::string id) const override;
};


#endif //COMMAND_LINE_TOOL_NOT_ARGUMENT_PARSER_H
