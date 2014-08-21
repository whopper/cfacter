#include <facter/facts/linux/lsb_resolver.hpp>
#include <facter/facts/collection.hpp>
#include <facter/facts/fact.hpp>
#include <facter/facts/scalar_value.hpp>
#include <facter/execution/execution.hpp>
#include <facter/util/string.hpp>
#include <facter/util/regex.hpp>

using namespace std;
using namespace facter::util;
using namespace facter::execution;

namespace facter { namespace facts { namespace linux {

    lsb_resolver::lsb_resolver() :
        resolver(
            "Linux Standard Base",
            {
                fact::lsb_dist_id,
                fact::lsb_dist_release,
                fact::lsb_dist_codename,
                fact::lsb_dist_description,
                fact::lsb_dist_major_release,
                fact::lsb_dist_minor_release,
                fact::lsb_release,
            })
    {
    }

    void lsb_resolver::resolve_facts(collection& facts)
    {
        // Resolve all lsb-related facts
        resolve_dist_id(facts);
        resolve_dist_release(facts);
        resolve_dist_codename(facts);
        resolve_dist_description(facts);
        resolve_dist_version(facts);
        resolve_release(facts);
    }

    void lsb_resolver::resolve_dist_id(collection& facts)
    {
        auto os_value = facts.get<map_value>(fact::os, false);
        if (!os_value) {
          return;
        }

        auto lsb_value = os_value->get<map_value>("lsb");
        if (!release_value) {
          return;
        }

        auto lsb_dist_id = lsb_value->get<string_value>("dist_id");
        if (lsb_dist_id) {
            facts.add(fact::lsb_dist_id, make_value<string_value>(lsb_dist_id->value()));
        }
    }

    void lsb_resolver::resolve_dist_release(collection& facts)
    {
        auto os_value = facts.get<map_value>(fact::os, false);
        if (!os_value) {
          return;
        }

        auto lsb_value = os_value->get<map_value>("lsb");
        if (!release_value) {
          return;
        }

        auto lsb_dist_release = lsb_value->get<string_value>("dist_release");
        if (lsb_dist_release) {
            facts.add(fact::lsb_dist_release, make_value<string_value>(lsb_dist_release->value()));
        }
    }

    void lsb_resolver::resolve_dist_codename(collection& facts)
    {
        auto os_value = facts.get<map_value>(fact::os, false);
        if (!os_value) {
          return;
        }

        auto lsb_value = os_value->get<map_value>("lsb");
        if (!release_value) {
          return;
        }

        auto lsb_dist_codename = lsb_value->get<string_value>("dist_codename");
        if (lsb_dist_codename) {
            facts.add(fact::lsb_dist_codename, make_value<string_value>(lsb_dist_codename->value()));
        }
    }

    void lsb_resolver::resolve_dist_description(collection& facts)
    {
        auto os_value = facts.get<map_value>(fact::os, false);
        if (!os_value) {
          return;
        }

        auto lsb_value = os_value->get<map_value>("lsb");
        if (!release_value) {
          return;
        }

        auto lsb_dist_description = lsb_value->get<string_value>("dist_description");
        if (lsb_dist_description) {
            facts.add(fact::lsb_dist_description, make_value<string_value>(lsb_dist_description->value()));
        }
    }

    void lsb_resolver::resolve_dist_major_version(collection& facts)
    {
        auto os_value = facts.get<map_value>(fact::os, false);
        if (!os_value) {
          return;
        }

        auto lsb_value = os_value->get<map_value>("lsb");
        if (!release_value) {
          return;
        }

        auto lsb_dist_major_release = lsb_value->get<string_value>("dist_major_release");
        if (lsb_dist_major_release) {
            facts.add(fact::lsb_dist_major_release, make_value<string_value>(lsb_dist_major_release->value()));
        }
    }

    void lsb_resolver::resolve_dist_minor_version(collection& facts)
    {
        auto os_value = facts.get<map_value>(fact::os, false);
        if (!os_value) {
          return;
        }

        auto lsb_value = os_value->get<map_value>("lsb");
        if (!release_value) {
          return;
        }

        auto lsb_dist_minor_release = lsb_value->get<string_value>("dist_minor_release");
        if (lsb_dist_minor_release) {
            facts.add(fact::lsb_dist_minor_release, make_value<string_value>(lsb_dist_minor_release->value()));
        }
    }

    void lsb_resolver::resolve_release(collection& facts)
    {
        auto os_value = facts.get<map_value>(fact::os, false);
        if (!os_value) {
          return;
        }

        auto lsb_value = os_value->get<map_value>("lsb");
        if (!release_value) {
          return;
        }

        auto lsb_release = lsb_value->get<string_value>("release");
        if (lsb_release) {
            facts.add(fact::lsb_release, make_value<string_value>(lsb_release->value()));
        }
    }

}}}  // namespace facter::facts::linux
