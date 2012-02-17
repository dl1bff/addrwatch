#pragma once
#include "addrwatch.h"

#include <stdint.h>
#include <net/ethernet.h>

struct mcache_node {
	uint8_t l2_addr[ETH_ALEN];
	uint8_t ip_addr[16];
	time_t tstamp;
	uint8_t addr_len;

	struct mcache_node *next;
};

struct mcache_node *cache_lookup(uint8_t *l2_addr, uint8_t *ip_addr, uint8_t len, time_t t, struct mcache_node **cache);
void cache_prune(struct mcache_node *dead_node, struct mcache_node **cache);
void cache_del(struct mcache_node *dead_node, struct mcache_node **cache);

