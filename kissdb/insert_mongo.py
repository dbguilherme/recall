from pymongo import MongoClient
cliente = MongoClient('127.0.0.1', 27017)
banco = cliente.test_database
posts = banco.posts

for i in range(100000):
    post_data = {
    
        'title': 'Python and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDBPython and MongoDB',
        'content': 'PyMongo is fun, you guys',
        'author': str(i)
    }
    posts.insert_one(post_data)
    


bills_post = posts.find_one({'author': '1'})
print(bills_post)