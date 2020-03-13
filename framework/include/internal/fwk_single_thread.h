/*
 * Arm SCP/MCP Software
 * Copyright (c) 2015-2020, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FWK_INTERNAL_SINGLE_THREAD_H
#define FWK_INTERNAL_SINGLE_THREAD_H

#include <stdbool.h>
#include <fwk_event.h>
#include <fwk_list.h>

/*
 * Thread component context. Exposed for testing purposes only.
 */

struct __fwk_thread_ctx {
    /* Thread framework component initialization completed flag */
    bool initialized;

    /*
     * Counter used to generate event cookies.
     */
    uint32_t event_cookie_counter;

    /*
     * Queue of event structures that are free to be filled in and linked
     * to the event queue or the ISR event queue.
     */
    struct fwk_slist free_event_queue;

    /* Queue of events, generated by ISRs, that are awaiting processing */
    struct fwk_slist isr_event_queue;

    /* Queue of events that are awaiting processing */
    struct fwk_slist event_queue;

    /* The event currently being processed */
    struct fwk_event *current_event;
};

/*
 * \brief Get thread component context.
 *
 * \note Only for testing.
 */
struct __fwk_thread_ctx *__fwk_thread_get_ctx(void);

#endif /* FWK_INTERNAL_SINGLE_THREAD_H */
