//
// Created by virko on 10/27/2021.
//

#ifndef COMMAND_LINE_TOOL_OPTION_H
#define COMMAND_LINE_TOOL_OPTION_H

#include "int_argument.h"
#include "argument_parser.h"

class option {
public:
// a concrete `argument_parser` is injected through the constructor:
    option(std::string short_flag,
           std::string long_flag,
           std::string desc,
           bool arg,
           std::unique_ptr<argument_parser> parser);

    [[nodiscard]] const std::string &long_flag() const;

    [[nodiscard]] const std::string &short_flag() const;
     bool arg() const;
    [[nodiscard]] const std::string &desc() const;

    virtual std::string help() const;

    virtual bool can_parse(const char *arg) const;
    // virtual std::unique_ptr<argument> parse(char* args[]) const ;
    //  std::unique_ptr<argument>  whatever_i_do_to_parse_this_int(char *aargs) const;
    //     std::pair<char**, std::unique_ptr<argument>> parse(char* args[], int nargs) const;
    virtual ~option() = default;
    std::unique_ptr<argument> parse(const char* argn) const;
    // std::unique_ptr<argument> parse(char* args[], int nargs) const;
    [[nodiscard]] std::unique_ptr<argument> pparse() const;

private:

    std::string m_short;
    std::string m_long;
    std::string m_desc;
    std::unique_ptr<argument_parser> m_parser;
    bool argument;
};

#endif //COMMAND_LINE_TOOL_OPTION_H
