//
// Created by virko on 11/19/2021.
//


#include "../inc/int_argument_parser.h"

#include "../inc/int_argument.h"


#include <charconv>
#include <iostream>


std::unique_ptr<argument> int_argument_parser::parse(std::string id,const char* string) const {
    int n;
    std::string_view sv{string};
    auto[ptr, ec] = std::from_chars(sv.data(), sv.data() + sv.size(), n);
    if (ec == std::errc()) {
        return std::make_unique<int_argument>(std::move(id), n);
    }
    return nullptr;

}


