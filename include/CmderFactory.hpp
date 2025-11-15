#ifndef ADAS_CMDERFACTORY_HPP
#define ADAS_CMDERFACTORY_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "Command.hpp"

namespace adas
{

    // 把字符串 "MLRT" 解析成 ICommand 列表
    class CmderFactory
    {
    public:
        CmderFactory();

        std::string Normalize(const std::string &s) const noexcept;

        std::vector<std::unique_ptr<ICommand>>
        Parse(const std::string &cmds) const noexcept;

    private:
        std::unordered_map<char, std::unique_ptr<ICommand>> cmdMap_;
    };

} // namespace adas

#endif // ADAS_CMDERFACTORY_HPP
