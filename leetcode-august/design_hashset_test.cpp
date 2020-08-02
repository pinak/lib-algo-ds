#include <catch2/catch.hpp>
#include "design_hashset.hpp"

#include <vector>

TEST_CASE("Hashset test") {

    enum Operation {
        ADD,
        CHECK,
        REMOVE
    };

    struct OperationValue {
        Operation operation{};
        int argument{};
    };

    struct TestCaseEntry {
        string name;
        std::vector<OperationValue> operations;
        std::vector<bool> results;
    };
    

    auto cases = std::vector<TestCaseEntry>{
        {
            "Non existent",
            {{CHECK, 5}},
            {false}
        },
        {
            "Simple add check remove",
        {
            {CHECK, 5},    {ADD, 5},   {CHECK, 5}, {CHECK, 20},    {REMOVE, 5},    {CHECK, 5}},
            {false,         false,      true,       false,          false,          false}
        },
    };
    
    MyHashSet set;
    for (auto& test_case : cases) {
        

        SECTION(test_case.name) {
            REQUIRE(test_case.operations.size() == test_case.results.size());
            for (int i = 0; i < test_case.operations.size(); ++i) {
                INFO("Input: " + to_string(i) + "\n");
                auto current_op = test_case.operations[i];
                switch(current_op.operation) {
                    case ADD: {
                        set.add(current_op.argument);
                        break;
                    }
                    case CHECK: {
                        REQUIRE(set.contains(current_op.argument) == test_case.results[i]);
                        break;
                    }
                    case REMOVE: {
                        set.remove(current_op.argument);
                        break;
                    }
                }
            }
        }
    }
}