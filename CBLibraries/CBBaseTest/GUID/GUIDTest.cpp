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

TEST(AGuid, ShouldNotBeNullWhenCreated)
{
	cb::base::GUID guid = cb::base::createGUID();

	ASSERT_THAT(guid.isNull(), Eq(false));
}

//-------------------------------------------------------------------

TEST(AGuid, ShouldBeEqualToOtherWhenBothConstructed)
{
	cb::base::GUID guid_one;
	cb::base::GUID guid_two;

	ASSERT_THAT(guid_one, Eq(guid_two));
}

//-------------------------------------------------------------------

TEST(AGuid, ShouldNotBeEqualToOtherWhenBothCreated)
{
	cb::base::GUID guid_one = cb::base::createGUID();
	cb::base::GUID guid_two = cb::base::createGUID();

	ASSERT_THAT(guid_one, Ne(guid_two));
}

//-------------------------------------------------------------------

TEST(AGuid, ShouldBeSmallerThenCreatedGuidWhenItsNull)
{
	cb::base::GUID guid_one;
	cb::base::GUID guid_two = cb::base::createGUID();

	ASSERT_THAT(guid_one < guid_two, Eq(true));
}

//-------------------------------------------------------------------

TEST(AGuid, ShouldBeBiggerThenConstructedGuidWhenItsCreated)
{
	cb::base::GUID guid_one;
	cb::base::GUID guid_two = cb::base::createGUID();

	ASSERT_THAT(guid_two > guid_one, Eq(true));
}

//-------------------------------------------------------------------