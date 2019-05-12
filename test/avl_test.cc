#include <catch2/catch.hpp>
#include <lib-algo-ds/avl.h>

#include <algorithm>

TEST_CASE("avl rotation tests") {
    AvlTree tree;
    auto constexpr v = "some value";
    
    using namespace std;
    vector<pair<int, string>> const values = {
        {40, v},
        {30, v},
        {50, v},
        {29, v},
        {31, v},
    };

    for (auto const value : values) {
        tree.put(value.first, value.second);
    }
    /*  we have a tree that looks like:
                 40
               /     \
              30     50
             /  \   
            29  31

    */
    
    auto root = tree.root();
    REQUIRE(root->key == 40);
    REQUIRE(tree.height() == 3);
    REQUIRE(root->left->key == 30);
    REQUIRE(root->right->key == 50);

    SECTION("left left case") {
        /*

        inserting 28 will make the tree look like:

                  40
                /     \
               30     50
              /  \   
             29  31 
            /
           28
        This will voilate the balance  on the root and cause right rotation on root balance the tree to:

                   30
                /     \
               29     40
              /      /  \
             28     31   50
            

        */
        tree.put(28, v);
        auto root = tree.root();
        REQUIRE(root->key == 30);
        REQUIRE(root->left->key == 29);
        REQUIRE(root->right->key == 40);

        REQUIRE(tree.height() == 3);

    }

    SECTION("left right case") {

         /*

        inserting 32 will make the tree look like:

                  40
                /     \
               30     50
              /  \   
             29  31 
                    \
                    32
        This will voilate the balance  on the root and cause left rotation on 30 right rotation on root balance the tree to:

                   31
                /     \
               30     40
              /      /  \
             29     32   50
            

        */

        tree.put(32, v);
        auto root = tree.root();
        REQUIRE(root->key == 31);
        REQUIRE(root->left->key == 30);
        REQUIRE(root->right->key == 40);

        REQUIRE(tree.height() == 3);
    }
    

}