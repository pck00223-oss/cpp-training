#include "CmderFactory.hpp"
#include <cctype>

namespace adas
{

    CmderFactory::CmderFactory()
    {
        cmdMap_['M'] = std::make_unique<MoveCommand>();
        cmdMap_['L'] = std::make_unique<TurnLeftCommand>();
        cmdMap_['R'] = std::make_unique<TurnRightCommand>();
        cmdMap_['T'] = std::make_unique<TurnRoundCommand>();
    }

    std::string CmderFactory::Normalize(const std::string &s) const noexcept
    {
        std::string out;
        out.reserve(s.size());
        for (unsigned char ch : s)
        {
            if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
                continue;
            out.push_back(static_cast<char>(std::toupper(ch)));
        }
        return out;
    }

    std::vector<std::unique_ptr<ICommand>>
    CmderFactory::Parse(const std::string &cmds) const noexcept
    {
        std::vector<std::unique_ptr<ICommand>> list;

        for (char c : Normalize(cmds))
        {
            auto it = cmdMap_.find(c);
            if (it != cmdMap_.end() && it->second)
            {
                list.push_back(it->second->clone());
            }
        }

        return list;
    }

} // namespace adas
