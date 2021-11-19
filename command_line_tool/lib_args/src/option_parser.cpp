//
// Created by virko on 10/29/2021.
//

#include <iostream>
#include "../inc/option_parser.h"

std::vector<std::unique_ptr<argument>> option_parser::parse(char *args[], int nargs) const {

    std::vector<std::unique_ptr<argument>> parsed;
// calculate the pointer to the end of the sequence
    const auto end = args + nargs;
    do {
        for (const auto &opt: m_options) {
// if an options can be parsed by this `opt`...

            if (opt->can_parse(*args)) {
                // check if opt is a flag option
                if (opt->get_number() == 0) {
                    // this is a flag
                } else {
                    // not a flag, parse arguments
                    ++args;
                    if (auto value = opt->parse(*args)) {
// only stores the result if parsing succeeded
                        parsed.push_back(std::move(value));
                    }
                }
                // we parsed this option, so stop iterating
                // over the possible options
                break;



// ...let it parse the argument


            }
        }
    } while (++args != end);
    return parsed;
}
// help

void option_parser::add_option(std::unique_ptr<option> a) {
    m_options.push_back(std::move(a));

}

bool option_parser::option_bool(const std::string &line) const {
    std::vector<argument> result{};
    std::string token{};
    std::istringstream iss{line};
    // current_option is not null if the next token is expected to be an extra argument
    // e.g. in "--input code.cpp": "--input" is an option's flag and "code.cpp" an extra argument
    //
    // if the last parsed token was "--input" then `current_option` would point
    // to an option associated with the "input" flag. In the next iteration "code.cpp" would be parsed.
    // this way the currently selected option can be linked with its argument
    while (iss >> token) {
        // if awaiting a new flag, try to match it
        if (is_short_flag(token)) {
            for (auto &opt: m_options) {
                if (opt->short_flag() == token.substr(1)) {
                    return true;
                }
            }
        } else if (is_long_flag(token)) {
            for (auto &opt: m_options) {
                if (opt->long_flag() == token.substr(2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool option_parser::is_short_flag(const std::string &flag) const {
    return flag.length() == 2 && flag[0] == '-' && flag[1] != '-';
}

bool option_parser::is_long_flag(const std::string &flag) const {
    return flag.length() >= 4 && flag[0] == '-' && flag[1] == '-';
}








