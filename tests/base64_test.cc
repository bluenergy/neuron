#include <gtest/gtest.h>

#include "utils/base64.h"

TEST(Base64Test, neu_encode64_test)
{
    const char *input = "hello world!";
    size_t      len   = strlen(input);
    char *      b64   = neu_encode64((unsigned char *) input, len);
    EXPECT_STREQ(b64, "aGVsbG8gd29ybGQh");
    free(b64);
}

TEST(Base64Test, neu_decode64_test)
{
    int            len       = 0;
    const char *   input     = "aGVsbG8gd29ybGQh";
    const char *   output    = "hello world!";
    char           temp[100] = { '\0' };
    unsigned char *data      = neu_decode64(&len, input);
    memcpy(temp, data, len);
    free(data);
    EXPECT_STREQ(temp, output);
    EXPECT_EQ(len, strlen(output));
}