#include <sstream>
#include <vector>
#include <string>
#include <optional>
#include <iomanip>
#include <functional>

using namespace std;

class Solution {
    
public:
    
    class Time {
    public:
        static optional<Time> create(int hours, int minutes) {
            if (hours > 23 || hours < 0 || minutes > 59 || minutes < 0) {
                return nullopt;
            }
            return Time(hours, minutes);
        }
        
        int hash() const {
            return _hours * 60 + _minutes;
        }
        
        bool operator==(Time const& b) {
            return this->hash() == b.hash();
        }
        
        bool operator>(Time const& b) {
            return this->hash() > b.hash();
        }
        
        bool operator<(Time const& b) {
            return this->hash() < b.hash();
        }
        
        string toString() {
            std::ostringstream strstream;
            strstream << std::setw(2) << std::setfill('0')  << _hours <<
                ":" << std::setw(2) << std::setfill('0') << _minutes;
            return strstream.str();
        }
        
    private:
        Time(int hours, int minutes)
        : _hours{hours}, _minutes{minutes}{}
        
        int _hours;
        int _minutes;
    };
    
    string largestTimeFromDigits(vector<int>& A) {
        std::sort(A.begin(), A.end());
        
        std::optional<Time> max_time{nullopt};
        
        do {
            int hours = A[0] * 10 + A[1];
            int minutes = A[2] * 10 + A[3];
            auto current_time = Time::create(hours, minutes);
            if (!current_time) {
                continue;
            }
            
            if (!max_time) {
                max_time = current_time;
            }
            
            max_time = max_time.value() < current_time.value() ? current_time : max_time;
            
        } while (std::next_permutation(A.begin(), A.end()));
        
        if (!max_time) {
            return {};
        }     
        return max_time->toString();
    }
};

/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.
*/

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("largest time digits") {
    struct TestCaseEntry {
        std::vector<int> test{};
        std::string result{};
    };
    

    auto cases = std::vector<TestCaseEntry>{
        {{1,2,3,4}, "23:41"},
        {{5,5,5,}, ""},
    };
    
    Solution s;
    for (auto& test_case : cases) {
        auto result = s.largestTimeFromDigits(test_case.test);
        REQUIRE(result == test_case.result);
    }
}