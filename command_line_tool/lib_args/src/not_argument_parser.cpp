//
// Created by virko on 11/21/2021.
//

#include "../inc/not_argument_parser.h"
#include "../inc/not_argument.h"

std::unique_ptr<argument> not_argument_parser::parsee(std::string id) const {

    return std::make_unique<not_argument>(std::move(id));
}
