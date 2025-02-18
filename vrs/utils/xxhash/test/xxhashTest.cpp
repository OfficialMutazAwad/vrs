// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <string>

#include <gtest/gtest.h>

#include <vrs/utils/xxhash/xxhash.h>

using namespace std;
using namespace vrs;

struct XXHTest : testing::Test {};

TEST_F(XXHTest, sums) {
  string a{"a"};
  string b{"b"};
  string c{"c"};
  string empty{""};
  XXH64Digester digester;
  digester.update(a);
  EXPECT_EQ(digester.digestToString(), "e513e02c99167f96");

  XXH64Digester digester2;
  digester2.update(a).update(b);
  EXPECT_EQ(digester2.digestToString(), "2b4d0fc9e4bf29e2");

  XXH64Digester digester3;
  digester3.update(a).update(b).update(c);
  EXPECT_EQ(digester3.digestToString(), "aff0f2a2f8b32731");

  XXH64Digester digester4;
  digester4.update(a + b + c);
  EXPECT_EQ(digester4.digestToString(), "fa5741489fa85bff");

  XXH64Digester digester5;
  digester5.update(b + c + a);
  EXPECT_EQ(digester5.digestToString(), "0195ef969615a6ee");

  XXH64Digester digester6;
  digester6.update(a + b).update(empty);
  EXPECT_EQ(digester6.digestToString(), "d997f8be8ae224f1");
}
