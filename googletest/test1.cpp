#include <gtest/gtest.h>
#include "../functions.h"

TEST(Studentas, GetMedianaTest) {
    // Create an instance of your class
    Studentas myObject;

    // Test case 1: Test with an odd number of elements
    myObject.setPazymiai({1.0, 3.0, 2.0});
    ASSERT_DOUBLE_EQ(myObject.getMediana(), 2.0);

    // Test case 2: Test with an even number of elements
    myObject.setPazymiai({4.0, 1.0, 3.0, 2.0});
    ASSERT_DOUBLE_EQ(myObject.getMediana(), 2.5);

    // Test case 3: Test with an empty vector
    myObject.setPazymiai({});
    // Handle the case where your function behavior for an empty vector is defined.
    // For example, you might throw an exception or return a default value.
    // ASSERT_THROW(myObject.getMediana(), SomeExceptionType);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}