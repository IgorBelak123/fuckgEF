//
// Created by virko on 10/27/2021.
//
#include "../inc/argument_parser.h"
#include "../inc/option.h"
#include <iostream>
#include <cstring>

option::option(std::string short_flag,
               std::string long_flag,
               std::string desc,
               std::unique_ptr<argument_parser> parser):
        m_short(std::move(short_flag)),
        m_long(std::move(long_flag)),
        m_desc(std::move(desc)),
        m_parser(std::move(parser))
{}


const std::string &option::long_flag() const {
    return m_long;
}

const std::string &option::short_flag() const {
    return m_short;
}

const std::string &option::desc() const {
    return m_desc;
}
std::string option::help() const {
    return "-s, --long_flag \t\t desc";
}

bool option::can_parse(const char *arg) const {
    if (arg == m_long || arg == m_short){
        return true;
    }
    else {
        return false;
    }
}

int option::arg() {
    number_arguments  = number_arguments+1;
    return number_arguments;
}



int option::get_number() const {
    return number_arguments;
}

void option::set_number(int a) {
    number_arguments = a;
}

std::unique_ptr<argument> option::parse(const char *arg) const {

    return m_parser->parse(m_long, arg);
}

