//
// Created by virko on 11/19/2021.
//

#include "../inc/dbl_argument.h"
#include "../inc/dbl_argument.h"

#include <utility>

dbl_argument::dbl_argument(std::string id, double value): argument(std::move(id)),m_value(value) {

}

double dbl_argument::value() const {
    return m_value;
}
