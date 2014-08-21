#include <facter/facts/posix/operating_system_resolver.hpp>
#include <facter/facts/posix/os.hpp>
#include <facter/facts/posix/os_family.hpp>
#include <facter/facts/scalar_value.hpp>
#include <facter/facts/map_value.hpp>
#include <facter/facts/collection.hpp>
#include <facter/facts/fact.hpp>
#include <map>

using namespace std;

namespace facter { namespace facts { namespace posix {

    operating_system_resolver::operating_system_resolver() :
        resolver(
            "operating system",
            {
                fact::os,
                fact::operating_system,
                fact::os_family,
                fact::operating_system_release,
                fact::operating_system_major_release
            })
    {
    }

    void operating_system_resolver::resolve_facts(collection& facts)
    {
        // Resolve all operating system related facts
        resolve_structured_operating_system(facts);
        resolve_operating_system(facts);
        resolve_os_family(facts);
        resolve_operating_system_release(facts);
        resolve_operating_system_major_release(facts);
    }

    void operating_system_resolver::resolve_structured_operating_system(collection& facts)
    {
        auto os_value = make_value<map_value>();
        auto operating_system = determine_operating_system(facts);
        auto os_family = determine_os_family(facts, operating_system);
        auto release = determine_operating_system_release(facts);
        if (!operating_system.empty()) {
            os_value->add("name", make_value<string_value>(operating_system));
        }

        if (!os_family.empty()) {
            os_value->add("family", make_value<string_value>(os_family));
        }

        if (!release.empty()) {
            auto release_value = make_value<map_value>();
            release_value->add("full", make_value<string_value>(release));
            os_value->add("release", move(release_value));
        }

        if (!os_value->empty()) {
            facts.add(fact::os, move(os_value));
        }
    }

    void operating_system_resolver::resolve_operating_system(collection& facts)
    {
        auto os_value = facts.get<map_value>(fact::os, false);
        if (!os_value) {
            return;
        }

        auto operating_system = os_value->get<string_value>("name");
        if (operating_system) {
            facts.add(fact::operating_system, make_value<string_value>(operating_system->value()));
        }
    }

    void operating_system_resolver::resolve_os_family(collection& facts)
    {
        auto os_value = facts.get<map_value>(fact::os, false);
        if (!os_value) {
            return;
        }

        auto os_family = os_value->get<string_value>("family");
        if (os_family) {
            facts.add(fact::os_family, make_value<string_value>(os_family->value()));
        }
    }

    void operating_system_resolver::resolve_operating_system_release(collection& facts)
    {
        auto os_value = facts.get<map_value>(fact::os, false);
        if (!os_value) {
            return;
        }

        auto release_value = os_value->get<map_value>("release");
        if (!release_value) {
            return;
        }

        auto operating_system_release = release_value->get<string_value>("full");
        if (operating_system_release) {
            facts.add(fact::operating_system_release, make_value<string_value>(operating_system_release->value()));
        }
    }

    string operating_system_resolver::determine_operating_system(collection& facts)
    {
        // Default to the same value as the kernel
        auto kernel = facts.get<string_value>(fact::kernel);
        if (!kernel) {
            return {};
        } else {
            return kernel->value();
        }
    }

    string operating_system_resolver::determine_os_family(collection& facts, string& operating_system)
    {
        auto os = operating_system;
        string value;
        if (!os.empty()) {
            static map<string, string> const systems = {
                { string(os::redhat),                   string(os_family::redhat) },
                { string(os::fedora),                   string(os_family::redhat) },
                { string(os::centos),                   string(os_family::redhat) },
                { string(os::scientific),               string(os_family::redhat) },
                { string(os::scientific_cern),          string(os_family::redhat) },
                { string(os::ascendos),                 string(os_family::redhat) },
                { string(os::cloud_linux),              string(os_family::redhat) },
                { string(os::psbm),                     string(os_family::redhat) },
                { string(os::oracle_linux),             string(os_family::redhat) },
                { string(os::oracle_vm_linux),          string(os_family::redhat) },
                { string(os::oracle_enterprise_linux),  string(os_family::redhat) },
                { string(os::amazon),                   string(os_family::redhat) },
                { string(os::xen_server),               string(os_family::redhat) },
                { string(os::linux_mint),               string(os_family::debian) },
                { string(os::ubuntu),                   string(os_family::debian) },
                { string(os::debian),                   string(os_family::debian) },
                { string(os::cumulus),                  string(os_family::debian) },
                { string(os::suse_enterprise_server),   string(os_family::suse) },
                { string(os::suse_enterprise_desktop),  string(os_family::suse) },
                { string(os::open_suse),                string(os_family::suse) },
                { string(os::suse),                     string(os_family::suse) },
                { string(os::solaris),                  string(os_family::solaris) },
                { string(os::nexenta),                  string(os_family::solaris) },
                { string(os::omni),                     string(os_family::solaris) },
                { string(os::open_indiana),             string(os_family::solaris) },
                { string(os::smart),                    string(os_family::solaris) },
                { string(os::gentoo),                   string(os_family::gentoo) },
                { string(os::archlinux),                string(os_family::archlinux) },
                { string(os::mandrake),                 string(os_family::mandrake) },
                { string(os::mandriva),                 string(os_family::mandrake) },
                { string(os::mageia),                   string(os_family::mandrake) },
            };
            auto const& it = systems.find(os);
            if (it != systems.end()) {
                value = it->second;
            }
        }

        if (value.empty()) {
            // Default to the same value as the kernel
            auto kernel = facts.get<string_value>(fact::kernel);
            if (!kernel) {
                return {};
            }
            value = kernel->value();
        }
        return value;
    }

    string operating_system_resolver::determine_operating_system_release(collection& facts)
    {
        // Default to the same value as the kernelrelease fact
        auto release = facts.get<string_value>(fact::kernel_release);
        if (!release) {
            return {};
        } else {
            return release->value();
        }
    }

}}}  // namespace facter::facts::posix
