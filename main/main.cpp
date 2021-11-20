#include <sstream>
#include <iostream>
#include "../command_line_tool/lib_args/inc/int_argument_parser.h"
#include "../command_line_tool/lib_args/inc/str_argument.h"
#include "../command_line_tool/lib_args/inc/dbl_argument.h"
#include "../command_line_tool/lib_args/inc/dbl_argument_parser.h"
#include "../command_line_tool/lib_args/inc/int_argument.h"
#include "../command_line_tool/lib_args/inc/option_parser.h"
#include "../../../../../C++/WOW/command_line_tool/program.h"
#include "../command_line_tool/lib_args/inc/option.h"
#include "memory.h"
#include "../command_line_tool/lib_args/inc/str_argument_parser.h"


int main(int argc, char *argv[]){


    option_parser parser{};


    parser.add_option(std::make_unique<int_option>("-l","--level","set the level", std::make_unique<str_argument_parser>()));
    parser.add_option(std::make_unique<option>("-l","--level","set the level", std::make_unique<dbl_argument_parser>()));
    parser.add_option(std::make_unique<option>("-l","--level","set the level", std::make_unique<int_argument_parser>()));

    auto arguments = parser.parse(argv, argc);
    //std::cout << "aaaaa";
    for (const auto& arg: arguments){
// args is of type std::unique_ptr<argument>

// obtain the raw pointer from the unique pointer
        argument* raw_arg = arg.get();
// use dynamic casting to convert to correct pointer type
        if (auto* int_arg = dynamic_cast<int_argument*>(raw_arg)) {
            std::cout << int_arg->id() << ": " << int_arg->value() << '\n';
        }
        else if (auto* dbl_arg = dynamic_cast<dbl_argument*>(raw_arg)){
            std::cout << dbl_arg->id() << ": " << dbl_arg->value() << '\n';

        }
        else if (auto* str_arg = dynamic_cast<str_argument*>(raw_arg)){
            std::cout << str_arg->id() << ": " << str_arg->value() << '\n';

        }
        else{
            std::cout << "Argument of unknown type for id: " << arg->id() << '\n';
        }
    }
}