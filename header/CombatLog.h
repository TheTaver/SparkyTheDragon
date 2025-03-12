#ifndef __COMBATLOG_H__
#define __COMBATLOG_H__
#include <string>
#include <vector>


class CombatLog {
    private:
        int maxLength;
        std::vector<std::wstring> log;
        static std::wstring to_wstring(std::string s) { return std::wstring(s.begin(), s.end()); };

        void LimitLength();
    public:
        CombatLog(int length = 10) : maxLength(length) {};

        const std::vector<std::wstring> getLog() const { return log; }
        
        void add(const std::string& newMessage) {
            add(to_wstring(newMessage));
        }

        void add(const std::wstring& newMessage) {
            log.push_back(newMessage);
            while(log.size() > maxLength) {
                // pop_front for vector, but requires moving all elements in log
                log.erase(log.begin());
            }
        }
    

};


#endif