//
// Created by virko on 11/19/2021.
//
#include "../../../../../Users/virko/CLionProjects/fuckgEF/command_line_tool/lib_args/inc/str_argument_parser.h"
#include "../../../../../Users/virko/CLionProjects/fuckgEF/command_line_tool/lib_args/inc/str_argument.h"

std::unique_ptr<argument> str_argument_parser::parse(std::string id, const char *string) const {
    return std::make_unique<str_argument>(std::move(id), string);
}
