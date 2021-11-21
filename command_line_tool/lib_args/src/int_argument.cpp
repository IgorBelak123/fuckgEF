//
// Created by virko on 11/19/2021.
//

#include <string>
#include <utility>
#include "../inc/int_argument.h"


int_argument::int_argument(std::string id, int value): argument(std::move(id)), m_value(value){
}
int int_argument::value() const {
    return m_value;
}

