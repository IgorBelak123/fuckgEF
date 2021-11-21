//
// Created by virko on 11/19/2021.
//

#include "../inc/dbl_argument_parser.h"

#include "../inc/argument_parser.h"
#include <iostream>
#include "../inc/dbl_argument_parser.h"
#include "../inc/dbl_argument.h"

std::unique_ptr<argument> dbl_argument_parser::parse(std::string id,const char* string) const {
    int n;
    std::string_view sv{string};
    auto[ptr, ec] = std::from_chars(sv.data(), sv.data() + sv.size(), n);
    if (ec == std::errc()) {
        std::cout << n << "hehe";
        return std::make_unique<dbl_argument>(std::move(id), n);
    }
    return nullptr;

}