#include <catch.hpp>
#include <sstream>

#include "queue.hpp"

TEST_CASE("creating queue")
{
	queue_t<int> queue;
	REQUIRE( queue.get_head() == nullptr );
	REQUIRE( queue.get_tail() == nullptr );
}

TEST_CASE("copy queue")
{
	queue_t<int> queue;
	queue_t<int> queue2;
	queue.push(3);
	queue.push(6);
	
	queue2.push(1);
	
	queue2 = queue;
	
	REQUIRE( queue2.headl(queue2.get_head()) == 3 );
	REQUIRE( queue2.taill(queue2.get_tail()) == 6 );
}

TEST_CASE("pushing elements int")
{
	queue_t <int> queue;

	queue.push(1);
	REQUIRE( queue.headl(queue.get_head()) == 1 );
	REQUIRE( queue.taill(queue.get_tail()) == 1 );

	queue.push(2);
	REQUIRE( queue.headl(queue.get_head()) == 1 );
	REQUIRE( queue.taill(queue.get_tail()) == 2 );

	queue.push(3);
	REQUIRE( queue.headl(queue.get_head()) == 1 );
	REQUIRE( queue.taill(queue.get_tail()) == 3 );
}

TEST_CASE("pushing elements double")
{
	queue_t <double> queue;

	queue.push(1);
	REQUIRE( queue.headl(queue.get_head()) == 1 );
	REQUIRE( queue.taill(queue.get_tail()) == 1 );

	queue.push(2);
	REQUIRE( queue.headl(queue.get_head()) == 1 );
	REQUIRE( queue.taill(queue.get_tail()) == 2 );

	queue.push(3);
	REQUIRE( queue.headl(queue.get_head()) == 1 );
	REQUIRE( queue.taill(queue.get_tail()) == 3 );
}

TEST_CASE("poping elements int")
{
	queue_t <int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);

	queue.pop();
	REQUIRE( queue.headl(queue.get_head()) == 2 );
	REQUIRE( queue.taill(queue.get_tail()) == 4 );

	queue.pop();
	REQUIRE( queue.headl(queue.get_head()) == 3 );
	REQUIRE( queue.taill(queue.get_tail()) == 4 );

	queue.pop();
	REQUIRE( queue.headl(queue.get_head()) == 4 );
	REQUIRE( queue.taill(queue.get_tailo()) == 4 );
}

TEST_CASE("poping elements double")
{
	queue_t <double> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);

	queue.pop();
	REQUIRE( queue.headl(queue.get_head()) == 2 );
	REQUIRE( queue.taill(queue.get_tail()) == 4 );

	queue.pop();
	REQUIRE( queue.headl(queue.get_head()) == 3 );
	REQUIRE( queue.taill(queue.get_tail()) == 4 );

	queue.pop();
	REQUIRE( queue.headl(queue.get_head()) == 4 );
	REQUIRE( queue.taill(queue.get_tail()) == 4 );
}

TEST_CASE("Error")
{
	queue_t<int> queue;
	REQUIRE_THROWS_AS( queue.pop() , std::logic_error);
}
