# How to use developer documentation

- i personally need to get better at using documentation

--------
### Link: https://www.youtube.com/watch?v=s1PLS3SQHQ0&t=91s

- the more time you spend in the documentation, the better of a developer that you will be
- search up keywords
- the better you get reading different documentation, the easier it is to find the things you want

steps:
1) identify the data type / structure you are working with
2) identify the goal you have and align it with a particular function
3) search the docs to see what you are looking for in this case

- the point of the documentation is to give you what the code looks like for you to use 

--------

### Useful Quotes I found off reddit

https://www.reddit.com/r/learnprogramming/comments/1larol4/do_you_use_the_documentation_or_ai_more/
https://www.reddit.com/r/learnprogramming/comments/1l72vdo/should_i_spend_hours_looking_through/
https://www.reddit.com/r/AskProgramming/comments/1i35c2z/how_to_read_documentation_like_a_pro/
https://www.reddit.com/r/learnprogramming/comments/1kxxu13/documentation_doesnt_work_for_me_am_i_the_problem/
https://www.reddit.com/r/learnprogramming/comments/1hdhi9j/tutorials_vs_documentation_what_works_for_you/
https://www.reddit.com/r/learnprogramming/comments/1gb9zpb/how_hard_is_it_to_learn_through_documentation/
https://www.reddit.com/r/learnprogramming/comments/1eyc544/how_did_you_start_understanding_documentation/

Notes of Said Posts:

- an important thing about the docs is that you get your own searching feature in your brain when looking up things, you have to read the docs for a while so you know when ai is feeding you slop or not
- documentation > google > ai
- docs for learning, ai for fixing syntax??, maybe not for fixing issues though
- AI can help augment productivity, but shouldn’t completely replace your critical thinking in designing and developing software.
- If you could not do it yourself, dont ask AI to do it for you, but maybe ask AI where to find the information to fix the problem instead?
"Hey, am struggling with building a makefile, could you give me 5 sources where to learn the correct syntax? Alao, what are some of the best books about it? Whats the most common error people have while trying to make their own?"
Stuff like that, AI can still save you time without giving you the answer and stealing the learning opportunities.


Yeah, this is super common and honestly you're already aware of it which is half the battle. Here's what actually works: set hard rules for yourself, like no AI for the first 30 minutes of being stuck, then you can use it to check your approach or get a hint rather than the full solution. The key difference is asking "why doesn't this work" instead of "write this for me".

Also try coding in an environment where you can't easily access AI, like offline or on your phone without it nearby. Sounds silly but friction helps a lot at 16 when willpower is still developing.

The frustration you're feeling when coding without AI is actually a good sign, that's where learning happens. Push through it for like 10 minutes before you even think about asking for help. You'll be surprised how often you figure it out.

One more thing: use AI to explain concepts or debug your own code after you've attempted it, not to write it from scratch. There's a huge difference between "why is my loop not working" and "write me a loop". The first teaches you, the second doesn't.

You're already thinking about this at 16 which puts you ahead of a lot of people who just coast. Stick with it and the dependency will fade once you realize you actually can solve these things yourself.

--------

### blog post : https://learncodethehardway.com/blog/25-how-to-read-programmer-documentation/

- "the gestalt" > the gestalt is how all the parts of a pointing fit together to create an experience
- in relation to programming, the pieces of a library or something are really amazing, but programmers are really bad at putting those pieces together
- reading documentation requires active reading
- it means you have to type as you read, change the code to find more, and apply what you learn to your own problems to learn how to use what you learn
- the goal is to find the gestalt that the programmers ignored

##### step 1 - find the docs
1) ensure you found the right documentation (the latest one)
2) is it a guide or API description? you want to start at the guide
3) is there a cookbook or a guide with examples
4) what are the most interesting topics to You

##### step 2 - determine your strategy
1) you can find other peoples code
2) you can make a small project to try it

with pandas, you can start with the cookbook or how-to-document as a guide to dive developer
try to make use of the api references

##### step 3 - code first, docs second
start with the code, then read about it. it is good because you can experience the code, which helps with understanding

looking at the pandas docs
stuff like

```
Customarily, we import as follows.

Creating a Series by passing a list of values, letting
pandas create a default RangeIndex.

Creating a DataFrame by passing a NumPy array with a
datetime index using date_range() and labeled columns:
```
make no sense, but if you try the code, it helps fill gaps in your understanding

##### step 4: break or change the code
1 big issue for beginners is being able to decipher the convoluted error messages > the best solution is to keep yourself in that many errors on purpose so that you can study it
2 another thing you can do is ask if you can do something different and try it > trying different combinations of stuff of what you learned

##### step 5: take notes

take notes and snippets and document what you learned
keep **links**  of your data to help you remember when you read something

##### step 6: use it on your own
you want to be someone who can use the language to express your own ideas > so once you have enough understanding you switch to the api references > you dont want to passively read docs > copy an example from the docs then modify it > after tutorials you want details like function signatures, parameters, edge cases

##### step 7: write about what you learned

author: "programming forces me to structure my understanding of how something works into logical steps and structures. after i turn a process or idea into code I understand how it could actually work"

i think this point relates to richard feynmans point of like if you can explain something then you actually understand it

ensure you can explain the stuff and write about the stuff you learned - that will help us in the long run

##### step 8: find the gestalt
make sure we can summarize the project
