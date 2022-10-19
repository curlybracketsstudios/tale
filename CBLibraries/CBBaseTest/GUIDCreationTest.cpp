#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBBase/GUID/GUID.h"

//-------------------------------------------------------------------

TEST(AGuid, ShouldBeNullWhenConstructed)
{
	cb::base::GUID guid;

	ASSERT_THAT(guid.isNull(), Eq(true));
}

//-------------------------------------------------------------------