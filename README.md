# BoardGameCardOCR

Personal Project for own use only. Goal is to create database of my family's boardgame cards. I have pictures (~500 so far) which contain from 2 to 20 cards each.

Plan:

- Use TensorFlow object detection to detect and classify the cards. I have 10 different classes so far.
- Create GUI for this process so that I can verify cards are classified and cropped properly from the input image.
- Use TesseractOCR to read the text from the individual cards. Classify the text into different categories.
- Create GUI for this process so that I can verify that the text is read correctly.
- Save the information from the cards into a database.
- Create program for displaying the info from the database. GUI for this too.
