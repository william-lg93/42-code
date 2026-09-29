*This activity has been created as part of the 42 curriculum by wineto-m*

# NetPractice

## Description

NetPractice is a networking training activity from the 42 curriculum designed to help students understand the fundamentals of computer networks through interactive exercises.

The goal of the project is to configure network devices correctly so that hosts can communicate according to the requirements of each level. Throughout the activity, students practice identifying and fixing networking issues by configuring IP addresses, subnet masks, default gateways, routers, and routing paths.

The activity consists of 10 progressively more challenging levels, each introducing new networking concepts and requiring a correct network configuration to complete.

---

## Instructions

### Running the Training Interface

The training interface can be started by running:

```bash
./run.sh
```

This launches the NetPractice interface in your web browser, where each level can be completed interactively.

### Exporting Configurations

After successfully completing a level:

1. Click **Export** in the interface.
2. Save the generated configuration file.
3. Repeat the process for every level.

### Submission Requirements

Your Git repository must contain:

- The `README.md` file at the repository root.
- **10 exported configuration files**, **one for each level**, placed directly at the repository root.

Example:

```
README.md
level1.json
level2.json
...
level10.json
```

(Exported filenames may vary depending on the NetPractice version.)

---

## Networking Concepts Studied

This activity covers the following networking concepts:

- IPv4 addressing
- TCP/IP addressing
- Subnet masks
- Network prefixes (CIDR notation)
- Default gateways
- Routers
- Switches
- Local Area Networks (LANs)
- Routing between networks
- Packet forwarding
- Broadcast domains
- Network topology
- Basic troubleshooting
- OSI model layers
- Communication between hosts

---

## Resources

### Official Documentation

- 42 NetPractice subject
- RFC 791 – Internet Protocol (IP)
- RFC 950 – Internet Standard Subnetting Procedure
- RFC 1918 – Address Allocation for Private Internets

### Additional Learning Resources

- Cisco Networking Academy
- MDN Web Docs – Networking
- Cloudflare Learning Center – Networking Basics
- IBM Networking Concepts Documentation

### AI Usage

AI was used as an assistant for:

- Improving the wording and grammar of this README.
- Clarifying networking terminology.
- Explaining networking concepts during learning.
- Reviewing documentation for readability and completeness.

All network configurations, exercises, testing, and exported solutions were completed and verified by the student(s).

---

## License

This project is part of the 42 curriculum and is intended for educational purposes.
