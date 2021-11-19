//
// Created by virko on 11/19/2021.
//

#ifndef COMMAND_LINE_TOOL_OPTION_PARSER_H
#define COMMAND_LINE_TOOL_OPTION_PARSER_H


#include <vector>
#include "memory"
#include "sstream"
#include "option.h"

class option_parser{

public:
    // option_parser(int count_agument);
    bool is_long_flag(const std::string& flag) const;
    bool is_short_flag(const std::string& flag) const;
    bool option_bool(const std::string &line) const;
    std::vector<std::unique_ptr<argument>> parse(char *args[], int nargs) const;
    void add_option(std::unique_ptr<option> a);



private:
    std::vector<std::unique_ptr<option>> m_options;

};

#endif //COMMAND_LINE_TOOL_OPTION_PARSER_H
