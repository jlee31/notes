# System Design Concepts Course and Interview Prep

https://www.youtube.com/watch?v=F2FmTdLtb_4

### Computer Architecture (Disk Storage, RAM, Cache, CPU)

- bits (0 or 1)
- bytes (8 bits) > megabyte > gigabite > terabyte
- computer storage is either HDD or SSD
- harddrive also holds the operating systems
- RAM - random access memory - primary active memory - requires power and will be lost if you restart the computer
- cache memory: extremely fast memory
- goes from CPU checks L1 then L2 then L3 cache then RAM (reduces average time to access data)
- CPU - control processing units - controls processing
- GPU - graphics processsing units - controls graphics
- motherboard - component that connects everything (creates pathways)
- compilers convert code into machine code that be executed by the cpu

### Production App Architecture (CI/CD, Load Balancers, Logging & Monitoring)

- CI/CD - enures code from repo to production through tests without any manual interventions (Jenkins or github actions)
- Load Balancer and reverse proxies evenly distribute traffic between servers
- Data is stored with external storage servers on a different server connected by a different network
- Logging and Monitoring systems are used to log and analyze data

![alt text](image.png)

### Design Requirements (CAP Theorem, Throughput, Latency, SLOs and SLAs)

- There are three pillars of system design
- What makes a good design: Scalability, Maintainability, Efficiency

- With data there are three important pillars
1) moving data
- securely moving data
2) storing data
- making efficiency access patterns, indexing strategies and creating backups
3) transforming data
- take raw data and turning it into meaningful information

CAP Theorem / Brewer's Theorem

- set principles that guides us when making informed tradeoffs

1) consistency - all nodes have data at the same time
2) availability - system is always operational and responsive to requests (regardless to number of traffic)
- measured in the amount of uptime and downtime (time when servers are running)

SLO : service level objectives
ex. during uptime, we want data to lead in 300ms 99.9% of the time

SLA : service level agreements
ex. we tell the clients a minimum level of service that we are committed to provide

3) partition tolerance - systems ability to continue function even if a network partition occurs 
- systems can only have two of the three
- its about findinf the best solution for our specific use-case

![alt text](image-1.png)

reliability
- ensuring systems work consistenly and constantly

fault tolerance
- how does system handle random failures

redundancy
- random backups to ensure that if a system fails, the another system can go over

speed:
1) throughput
- measures how much data our system can handle over a certain period of time
- server throughput - RPS (requests per second) - how many server requests can a system handle in a period of time
- higher RPS is better
- DB throughput - QPS (queries per second) 
- data throughput - BPS (bytes per second)  

2) latency
- how long it takes to handle a single request
- optimizing for latency could decrease throughout

### Networking (TCP, UDP, DNS, IP Addresses & IP Headers)

- how computers communicate 

the heart of it: IP address

- unique address for each device on the network
- IPv4 - 32 bit - 4B addresses
- IPv6 - 128 bit address - 340T different addresses
- IP Header - has essential information (like IP address)
- Internet Protocol - set of rules that defines how data is sent and recieved
- Application Layer - where data specific to the application is stored (HTTP data would have webbrowsing data in a certain format/language so it can processed)

Transport Layer

- TCP: Transmission Control Protocol
- has a TCP header 
- it garentees delivery of packets
- ensures complete and correct flow 
- uses 3 way handshake

- UDP: User Datagram Protocol
- faster but less reliable
- does not establish a connection beforehand
- does not ensure delivery
- usually better for time sensitive systems (like live-streamings)

DNS 

- domain name system - converts urls to corresponding IP address to create a connection to the server
- uses ICANN (Internet Corporation for assigned names and numbers)
- A Record: maps a domain to an IPv4 Address
- AAAA Record: maps a domain to an IPv6 Address

Networking Infrastructure

- devices have either a public or private IP address (public is accessable anywhere, private where only local devices can see)
- they can be static or dynamic
- LAN (Local Area Network)
- Firewalls are used to monitor and control incoming and outgoing network traffic
- Ports are used with IP address to create a unique identifier for a network service
- Some ports are saved - like 80 is for HTTP, 443 for HTTPS, 22 for SSH, and etc

### Application Layer Protocols (HTTP, WebSockets, WebRTC, MQTT, etc)

HTTP 
- hypertext transfer protocol
- build on TCP/IP
- it is like a conversation with no memory (no data is stored)
- requests just have all the information you need
- it has status codes to give information to understand how a request is recieved
- 2xx for success, 3xx for redirection, 4xx for client error, 5xx for server error
- HTTP Methods: GET POSTS PUT DELETE

Websockets
- a two way communication channel
- allows applications to instantly communicate (like live chats or stock markets)

Email related protocols
- SMTP: Email transmission across the internet
- IMAP (Internet message access protocol): Used to retrieve emails from a server
- POP3 (Post Office Protocol version 3): Downloading emails from a server 

File Transfer Protocols:
- FTP: For transferring files over the internet
- SSH: Secure Shell: for command-line login and file transfer

Real-time Communication
- WebRTC: enables browser-to-broswer applications for voice calling, video chat and file sharing 
- MQTT (message queuing telemetry transport): lightweight messaging protocol
- AMQP (Advanced message queuing protcol): protocol for message-oriented middleware

RPS (Remote Procedure Call)
- allows computers to execute code on another server or computer

### API Design

- we define the inputs and outputs
- CRUD : Create Read Update Delete
- Create: /api/products/POST
- Read: /api/products/GET
- Update: /api/prodicts/:id
- Delete: /api/products/:id

how does it communicate?
- can be either HTTP/Websockets

what type of data?:
- JSON/XML

API Paradigms
1) REST : Representional state transfer
- it is stateless 
- uses standard HTTP Methods
- can have over-fetching and under-fetching
- uses JSON for data exchange

2) GraphQL
- avoids over-fetching and under-fetching by allowing exact amounts of data to be send over
- strongly typed schema based queries
- queries can impact server performance
- all requests are sents POST requests
- all responses are HTTP 200 (which can be unhelpful if you get an error)

3) gRPC
- built on HTTP/2 but requires this type of support to operate
- multiplexing / serving pushing
- uses protocol buffers
- efficient
- less human-readable

Backward Compatibility and Version
- when modifying endpoints, you want these things to make sure that changes don't break existing systems
- versioning ensures that you can handle requests from both current and old clients

Rate Limiter
- ensures there are not too many requests sent to an API

### Caching and CDNs

### Proxy Servers (Forward/Reverse Proxies)

### Load Balancers

### Databases (Sharding, Replication, ACID, Vertical & Horizontal Scaling)
