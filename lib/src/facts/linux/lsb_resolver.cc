#include <facter/facts/linux/lsb_resolver.hpp>
#include <facter/facts/collection.hpp>
#include <facter/facts/fact.hpp>
#include <facter/facts/scalar_value.hpp>
#include <facter/facts/map_value.hpp>
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
        construct_lsb_map(facts);
    }

    void lsb_resolver::resolve_dist_id(collection& facts)
    {
        auto result = execute("lsb_release", {"-i", "-s"});
        if (!result.first || result.second.empty()) {
            return;
        }
        facts.add(fact::lsb_dist_id, make_value<string_value>(move(result.second)));
    }

    void lsb_resolver::resolve_dist_release(collection& facts)
    {
        auto result = execute("lsb_release", {"-r", "-s"});
        if (!result.first || result.second.empty()) {
            return;
        }
        facts.add(fact::lsb_dist_release, make_value<string_value>(move(result.second)));
    }

    void lsb_resolver::resolve_dist_codename(collection& facts)
    {
        auto result = execute("lsb_release", {"-c", "-s"});
        if (!result.first || result.second.empty()) {
            return;
        }
        facts.add(fact::lsb_dist_codename, make_value<string_value>(move(result.second)));
    }

    void lsb_resolver::resolve_dist_description(collection& facts)
    {
        auto result = execute("lsb_release", {"-d", "-s"});
        if (!result.first || result.second.empty()) {
            return;
        }

        // The value may be quoted; trim the quotes
        facts.add(fact::lsb_dist_description, make_value<string_value>(trim(move(result.second), { '\"' })));
    }

    void lsb_resolver::resolve_dist_version(collection& facts)
    {
        auto dist_release = facts.get<string_value>(fact::lsb_dist_release, false);
        auto dist_id = facts.get<string_value>(fact::lsb_dist_id, false);
        if (!dist_release) {
            return;
        }

        string major;
        string minor;
        string regex;
        if (dist_id && dist_id->value() == "Ubuntu") {
            regex = "(\\d+\\.\\d*)\\.?(\\d*)";
        } else {
            regex = "(\\d+)\\.(\\d*)";
        }
        if (!re_search(dist_release->value(), regex, &major, &minor)) {
            major = dist_release->value();
        }
        facts.add(fact::lsb_dist_major_release, make_value<string_value>(move(major)));

        if (!minor.empty()) {
            facts.add(fact::lsb_dist_minor_release, make_value<string_value>(move(minor)));
        }
    }

    void lsb_resolver::resolve_release(collection& facts)
    {
        auto result = execute("lsb_release", {"-v", "-s"});
        if (!result.first || result.second.empty()) {
            return;
        }
        facts.add(fact::lsb_release, make_value<string_value>(move(result.second)));
    }

    map<string, string> lsb_resolver::construct_lsb_map(collection& facts)
    {
        //  Collect LSB data
        map<string, string> lsb_value;
        auto lsb_dist_id = facts.get<string_value>(fact::lsb_dist_id, false);
        auto lsb_dist_release = facts.get<string_value>(fact::lsb_dist_release, false);
        auto lsb_dist_codename = facts.get<string_value>(fact::lsb_dist_codename, false);
        auto lsb_dist_description = facts.get<string_value>(fact::lsb_dist_description, false);
        auto lsb_dist_major_release = facts.get<string_value>(fact::lsb_dist_major_release, false);
        auto lsb_dist_minor_release = facts.get<string_value>(fact::lsb_dist_minor_release, false);
        auto lsb_release = facts.get<string_value>(fact::lsb_release, false);
        if (lsb_dist_id) {
            lsb_value["distid"] = lsb_dist_id->value();
        }

        if (lsb_dist_release) {
            lsb_value["distrelease"] = lsb_dist_release->value();
        }

        if (lsb_dist_codename) {
            lsb_value["distcodename"] = lsb_dist_codename->value();
        }

        if (lsb_dist_description) {
            lsb_value["distdescription"] = lsb_dist_description->value();
        }

        if (lsb_dist_major_release) {
            lsb_value["majdistrelease"] = lsb_dist_major_release->value();
        }

        if (lsb_dist_minor_release) {
            lsb_value["minordistrelease"] = lsb_dist_minor_release->value();
        }

        if (lsb_release) {
            lsb_value["release"] = lsb_release->value();
        }

        return lsb_value;
    }

}}}  // namespace facter::facts::linux
