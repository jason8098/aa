provider "oci" {}

resource "oci_core_instance" "generated_oci_core_instance" {
	agent_config {
		is_management_disabled = "false"
		is_monitoring_disabled = "false"
		plugins_config {
			desired_state = "ENABLED"
			name = "Vulnerability Scanning"
		}
		plugins_config {
			desired_state = "ENABLED"
			name = "Compute Instance Monitoring"
		}
		plugins_config {
			desired_state = "DISABLED"
			name = "Bastion"
		}
	}
	availability_config {
		recovery_action = "RESTORE_INSTANCE"
	}
	availability_domain = "FHGC:AP-SINGAPORE-1-AD-1"
	compartment_id = "ocid1.tenancy.oc1..aaaaaaaazsyjzqdsj755ksak4qxowyrz62tnkav4hphgp2glx6ko6ysa52nq"
	create_vnic_details {
		assign_private_dns_record = "true"
		assign_public_ip = "true"
		subnet_id = "ocid1.subnet.oc1.ap-singapore-1.aaaaaaaa54owjns6235dcizn67jyzusiwi5bwmhjugg6pr6menxoxpzvbsgq"
	}
	display_name = "instance-20230728-1422"
	instance_options {
		are_legacy_imds_endpoints_disabled = "false"
	}
	metadata = {
		"ssh_authorized_keys" = "ssh-rsa AAAAB3NzaC1yc2EAAAABJQAAAQEArMNjI/sFPdv/IIbCNHbtc6nTUvYgng1ugkL53nKkw3DOoxmcxlrKGb1vSAmIbEJCOuVZKVl5qv6DBDqho+PBPoJV4v8FUs4lAQ623/wWDIqSqH40lGNgO3LCo0Ejspk4iIv9I+Eg6uxA5U6/DRrzPlM+TrHyex1OGeQ4sufwnIIRA+g3y+/K9ite0lF6Uq99+aQbw+Nje7RiY1wyvn+q/MgjJI76E4EpNC/97EiufvGl5+ieNcMCBBbqmDfu+wvcHnTFCPR5MysDDGuFnnJeXfYJl7NrMVCrvCECwKoVS9ngkGjyFHvBr/Iy1fCw/BTKx7AAfplOmkA/UMVcbzvNgw== oracle"
	}
	shape = "VM.Standard.A1.Flex"
	shape_config {
		memory_in_gbs = "24"
		ocpus = "4"
	}
	source_details {
		source_id = "ocid1.bootvolume.oc1.ap-singapore-1.abzwsljrdlscz47sogo4hec7ubamppnvwp4v4k63eixogta35cqemgutwwhq"
		source_type = "bootVolume"
	}
}
