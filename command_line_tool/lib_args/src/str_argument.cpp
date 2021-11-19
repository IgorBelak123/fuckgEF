//
// Created by virko on 11/19/2021.
//

#include "../inc/str_argument.h"

str_argument::str_argument(std::string id, std::string value): argument(id),m_value(value) {

}

std::string str_argument::value() const {
    return m_value;
}
