//
// Created by virko on 11/19/2021.
//
#include "../inc/argument.h"

argument::argument(std::string a): m_id(std::move(a)) {

}

const std::string &argument::id() const {
    return m_id;
}

