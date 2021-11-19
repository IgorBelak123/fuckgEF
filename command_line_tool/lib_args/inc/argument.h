//
// Created by virko on 10/27/2021.
//

#ifndef COMMAND_LINE_TOOL_ARGUMENT_H
#define COMMAND_LINE_TOOL_ARGUMENT_H
#include "sstream"
#include <charconv>
#include "sstream"
#include "memory"
class argument {
public:
    argument(std::string id);
    const std::string& id() const;
    virtual ~argument() = default;
private:
    std::string m_id;
};
#endif //COMMAND_LINE_TOOL_ARGUMENT_H
