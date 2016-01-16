#include <gtest/gtest.h>
#include <rai/node/wallet.hpp>

TEST (work, one)
{
	rai::work_pool pool;
    rai::change_block block (1, 1, rai::keypair ().prv, 3, 4);
    pool.generate (block);
    ASSERT_FALSE (pool.work_validate (block));
}

TEST (work, validate)
{
	rai::work_pool pool;
	rai::send_block send_block (1, 1, 2, rai::keypair ().prv, 4, 6);
    ASSERT_TRUE (pool.work_validate (send_block));
    pool.generate (send_block);
    ASSERT_FALSE (pool.work_validate (send_block));
}