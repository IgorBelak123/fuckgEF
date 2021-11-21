//
// Created by virko on 11/21/2021.
//

#include "../inc/not_argument.h"

#include <utility>




not_argument::not_argument(std::string id) : argument(std::move(id)) {

}
