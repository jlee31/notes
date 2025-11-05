# Why System Design is AI Proof (And How to Learn it)

https://www.youtube.com/watch?v=RDBTrg3YJSM

### Why AI is good at coding

why?
- because coding is a simple feedback loop
- does the code compile? yes then good if not then try something else
- you can quickly make unit tests to test, you can refactor code

how?
- there are also so many code examples, code repos and books online that chatgpt has seen before
- most coding path has a right enough implementation
- with a clear acceptance criteria, then llms can have an easy time



### Why AI is bad at system design

system design
- process of creating archietecture for large scale systems
- therefore you need to create databasee, api endpoints, how does data move and how everything interacts, deploys and scales
- compared to software, the feedback loop is extremely slow - there are a ton of different things that come together
- it takes years to determine if the code can scale, if the database can run
- there is no right answer and everything you do has a cost
- increasing availability increases latancy and decreases consistency
- you might have to work with legacy framework
- they are human problems designed for change, this is not something that ai is good at doing

main thing
- where traffic, scale and downstream service agreements interact create the most issues in system design 

### 5 Step System Design Framework

1) workloads and access patterns
- more reads or more writes?
- is there a reason why this part of the database would explode (like if taylor swift joined the app)
- consistent or bursty traffic

2) service level agreements and failure loads
- how durable is the data
- will the data be stored or lost if it crashes
- what happens if something fails
- do we have back pressure and timeouts in place in the entire system

3) data and consistency requirements
- source of truth for data (strong consistency or eventual consistency)

4) cost and evolution path
- how much does it cost to maintain and run the system
- in house vs aws
- how much more costs once things cost to scale
- is things scalable
- can you swap components
- are the versions
- can people use old stuff while using new stuff

5) reality of the org you are working in
- is the tech stack used by others

### How you can practice

- simple product
- product requirements doc (functional requirements, and non functional requirements)
- draft a design doc (traditional system design) - design for different levels of scale
- see what ai can create in comparison with your original design
- 