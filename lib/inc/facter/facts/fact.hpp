/**
 * @file
 * Declares the fact name constants.
 */
#ifndef FACTER_FACTS_FACT_HPP_
#define FACTER_FACTS_FACT_HPP_

namespace facter { namespace facts {

    /**
     * Stores the constant fact names.
     */
    struct fact
    {
        /**
         * The fact for kernel name.
         */
        constexpr static char const* kernel = "kernel";
        /**
         * The fact for kernel version.
         */
        constexpr static char const* kernel_version = "kernelversion";
        /**
         * The fact for kernel release.
         */
        constexpr static char const* kernel_release = "kernelrelease";
        /**
         * The fact for kernel major version.
         */
        constexpr static char const* kernel_major_version = "kernelmajversion";

        /**
         * The structured operatingsystem fact
         */
        constexpr static char const* os = "os";
        /**
         * The fact for operating system name.
         */
        constexpr static char const* operating_system = "operatingsystem";
        /**
         * The fact for operating system family name.
         */
        constexpr static char const* os_family = "osfamily";
        /**
         * The fact for operating system release.
         */
        constexpr static char const* operating_system_release = "operatingsystemrelease";
        /**
         * The fact for operating system major release.
         */
        constexpr static char const* operating_system_major_release = "operatingsystemmajrelease";

        /**
         * The fact for LSB distro id.
         */
        constexpr static char const* lsb_dist_id = "lsbdistid";
        /**
         * The fact for LSB distro release.
         */
        constexpr static char const* lsb_dist_release = "lsbdistrelease";
        /**
         * The fact for LSB distro codename.
         */
        constexpr static char const* lsb_dist_codename = "lsbdistcodename";
        /**
         * The fact for LSB distro description.
         */
        constexpr static char const* lsb_dist_description = "lsbdistdescription";
        /**
         * The fact for LSB distro major release.
         */
        constexpr static char const* lsb_dist_major_release = "lsbmajdistrelease";
        /**
         * The fact for LSB distro minor release.
         */
        constexpr static char const* lsb_dist_minor_release = "lsbminordistrelease";
        /**
         * The fact for LSB release.
         */
        constexpr static char const* lsb_release = "lsbrelease";

        /**
         * The fact for network hostname.
         */
        constexpr static char const* hostname = "hostname";
        /**
         * The fact for IPv4 address.
         */
        constexpr static char const* ipaddress = "ipaddress";
        /**
         * The fact for IPv6 address.
         */
        constexpr static char const* ipaddress6 = "ipaddress6";
        /**
         * The fact for interface MTU.
         */
        constexpr static char const* mtu = "mtu";
        /**
         * The fact for IPv4 netmask.
         */
        constexpr static char const* netmask = "netmask";
        /**
         * The fact for IPv6 netmask.
         */
        constexpr static char const* netmask6 = "netmask6";
        /**
         * The fact for IPv4 network.
         */
        constexpr static char const* network = "network";
        /**
         * The fact for IPv6 network.
         */
        constexpr static char const* network6 = "network6";
        /**
         * The fact for interface MAC address.
         */
        constexpr static char const* macaddress = "macaddress";
        /**
         * The fact for interface names.
         */
        constexpr static char const* interfaces = "interfaces";
        /**
         * The fact for domain name.
         */
        constexpr static char const* domain = "domain";
        /**
         * The fact for fully-qualified domain name (FQDN).
         */
        constexpr static char const* fqdn = "fqdn";
        /**
         * The fact for DHCP servers.
         */
        constexpr static char const* dhcp_servers = "dhcp_servers";

        /**
         * The fact for block device.
         */
        constexpr static char const* block_device = "blockdevice";
        /**
         * The fact for the list of block devices.
         */
        constexpr static char const* block_devices = "blockdevices";

        /**
         * The structured processor fact
         */
        constexpr static char const* processors = "processors";
        /**
         * The fact for processor descriptions.
         */
        constexpr static char const* processor = "processor";
        /**
         * The fact for logical processor count.
         */
        constexpr static char const* processor_count = "processorcount";
        /**
         * The fact for physical processor count.
         */
        constexpr static char const* physical_processor_count = "physicalprocessorcount";
        /**
         * The fact for processor instruction set architecture.
         */
        constexpr static char const* hardware_isa = "hardwareisa";
        /**
         * The fact for processor hardware model.
         */
        constexpr static char const* hardware_model = "hardwaremodel";

        /**
         * The fact for hardware architecture.
         */
        constexpr static char const* architecture = "architecture";
        /**
         * The fact for BIOS vendor.
         */
        constexpr static char const* bios_vendor = "bios_vendor";
        /**
         * The fact for BIOS version.
         */
        constexpr static char const* bios_version = "bios_version";
        /**
         * The fact for BIOS release date.
         */
        constexpr static char const* bios_release_date = "bios_release_date";
        /**
         * The fact for motherboard asset tag.
         */
        constexpr static char const* board_asset_tag = "boardassettag";
        /**
         * The fact for motherboard manufacturer.
         */
        constexpr static char const* board_manufacturer = "boardmanufacturer";
        /**
         * The fact for motherboard product name.
         */
        constexpr static char const* board_product_name = "boardproductname";
        /**
         * The fact for motherboard serial number.
         */
        constexpr static char const* board_serial_number = "boardserialnumber";
        /**
         * The fact for chassis asset tag.
         */
        constexpr static char const* chassis_asset_tag = "chassisassettag";
        /**
         * The fact for hardware manufacturer.
         */
        constexpr static char const* manufacturer = "manufacturer";
        /**
         * The fact for hardware product name.
         */
        constexpr static char const* product_name = "productname";
        /**
         * The fact for hardware serial number.
         */
        constexpr static char const* serial_number = "serialnumber";
        /**
         * The fact for hardware UUID.
         */
        constexpr static char const* product_uuid = "productuuid";
        /**
         * The fact for hardware chassis type.
         */
        constexpr static char const* chassis_type = "chassistype";

        /**
         * The structured uptime fact
         */
        constexpr static char const* system_uptime = "system_uptime";
        /**
         * The fact for system uptime.
         */
        constexpr static char const* uptime = "uptime";
        /**
         * The fact for system uptime, in days.
         */
        constexpr static char const* uptime_days = "uptime_days";
        /**
         * The fact for system uptime, in hours.
         */
        constexpr static char const* uptime_hours = "uptime_hours";
        /**
         * The fact for system uptime, in seconds.
         */
        constexpr static char const* uptime_seconds = "uptime_seconds";

        /**
         * The fact for selinux state.
         */
        constexpr static char const* selinux = "selinux";
        /**
         * The fact for selinux enforcement state.
         */
        constexpr static char const* selinux_enforced = "selinux_enforced";
        /**
         * The fact for selinux policy version.
         */
        constexpr static char const* selinux_policyversion = "selinux_policyversion";
        /**
         * The fact for current selinux mode.
         */
        constexpr static char const* selinux_current_mode = "selinux_current_mode";
        /**
         * The fact for selinux config mode.
         */
        constexpr static char const* selinux_config_mode = "selinux_config_mode";
        /**
         * The fact for selinux config policy.
         */
        constexpr static char const* selinux_config_policy = "selinux_config_policy";

        /**
         * The fact for SSH DSA public key.
         */
        constexpr static char const* ssh_dsa_key = "sshdsakey";
        /**
         * The fact for SSH RSA public key.
         */
        constexpr static char const* ssh_rsa_key = "sshrsakey";
        /**
         * The fact for SSH ECDSA public key.
         */
        constexpr static char const* ssh_ecdsa_key = "sshecdsakey";
        /**
         * The fact for SSH ED25519 public key.
         */
        constexpr static char const* ssh_ed25519_key = "sshed25519key";
        /**
         * The fact for SSH fingerprint of the DSA public key.
         */
        constexpr static char const* sshfp_dsa = "sshfp_dsa";
        /**
         * The fact for SSH fingerprint of the RSA public key.
         */
        constexpr static char const* sshfp_rsa = "sshfp_rsa";
        /**
         * The fact for SSH fingerprint of the ECDSA public key.
         */
        constexpr static char const* sshfp_ecdsa = "sshfp_ecdsa";
        /**
         * The fact for SSH fingerprint of the ED25519 public key.
         */
        constexpr static char const* sshfp_ed25519 = "sshfp_ed25519";

        /**
         * The fact for OSX system profiler boot mode.
         */
        constexpr static char const* sp_boot_mode = "sp_boot_mode";
        /**
         * The fact for OSX system profiler boot ROM version.
         */
        constexpr static char const* sp_boot_rom_version = "sp_boot_rom_version";
        /**
         * The fact for OSX system profiler boot volume.
         */
        constexpr static char const* sp_boot_volume = "sp_boot_volume";
        /**
         * The fact for OSX system profiler CPU type (processor name).
         */
        constexpr static char const* sp_cpu_type = "sp_cpu_type";
        /**
         * The fact for OSX system profiler current CPU speed.
         */
        constexpr static char const* sp_current_processor_speed = "sp_current_processor_speed";
        /**
         * The fact for OSX system profiler kernel version.
         */
        constexpr static char const* sp_kernel_version = "sp_kernel_version";
        /**
         * The fact for OSX system profiler L2 cache (per core).
         */
        constexpr static char const* sp_l2_cache_core = "sp_l2_cache_core";
        /**
         * The fact for OSX system profiler L3 cache.
         */
        constexpr static char const* sp_l3_cache = "sp_l3_cache";
        /**
         * The fact for OSX system profiler local host name (computer name).
         */
        constexpr static char const* sp_local_host_name = "sp_local_host_name";
        /**
         * The fact for OSX system profiler machine model (model identifier).
         */
        constexpr static char const* sp_machine_model = "sp_machine_model";
        /**
         * The fact for OSX system profiler machine name (model name).
         */
        constexpr static char const* sp_machine_name = "sp_machine_name";
        /**
         * The fact for OSX system profiler number of processors (total number of cores).
         */
        constexpr static char const* sp_number_processors = "sp_number_processors";
        /**
         * The fact for OSX system profiler OS version (system version).
         */
        constexpr static char const* sp_os_version = "sp_os_version";
        /**
         * The fact for OSX system profiler number of CPU packages (number of physical processors).
         */
        constexpr static char const* sp_packages = "sp_packages";
        /**
         * The fact for OSX system profiler physical memory.
         */
        constexpr static char const* sp_physical_memory = "sp_physical_memory";
        /**
         * The fact for OSX system profiler platform UUID (hardware UUID).
         */
        constexpr static char const* sp_platform_uuid = "sp_platform_uuid";
        /**
         * The fact for OSX system profiler secure virtual memory.
         */
        constexpr static char const* sp_secure_vm = "sp_secure_vm";
        /**
         * The fact for OSX system profiler serial number (system).
         */
        constexpr static char const* sp_serial_number = "sp_serial_number";
        /**
         * The fact for OSX system profiler SMC version (system).
         */
        constexpr static char const* sp_smc_version_system = "sp_smc_version_system";
        /**
         * The fact for OSX system profiler uptime (since boot).
         */
        constexpr static char const* sp_uptime = "sp_uptime";
        /**
         * The fact for OSX system profiler user name.
         */
        constexpr static char const* sp_user_name = "sp_user_name";

        /**
         * The fact for OSX build version.
         */
        constexpr static char const* macosx_buildversion = "macosx_buildversion";
        /**
         * The fact for OSX product name.
         */
        constexpr static char const* macosx_productname = "macosx_productname";
        /**
         * The fact for OSX product version.
         */
        constexpr static char const* macosx_productversion = "macosx_productversion";
        /**
         * The fact for OSX build major version.
         */
        constexpr static char const* macosx_productversion_major = "macosx_productversion_major";
        /**
         * The fact for OSX build minor version.
         */
        constexpr static char const* macosx_productversion_minor = "macosx_productversion_minor";

        /**
         * The fact for virtualization hypervisor.
         */
        constexpr static char const* virtualization = "virtual";
        /**
         * The fact for whether or not the machine is virtual or physical.
         */
        constexpr static char const* is_virtual = "is_virtual";
    };

}}  // namespace facter::facts

#endif  // FACTER_FACTS_FACT_HPP_
