import json

import telebot
from telebot import types



with open("adminbot.config", "r") as read_file:
    global config
    config = json.load(read_file)

bot = telebot.TeleBot(config["token"], parse_mode=None)


def userIsAdmin(user_id):
    return str(user_id) in config["admins"]
    

@bot.message_handler(commands=['start'])
def start(message):
    if userIsAdmin(message.from_user.id):
        bot.send_message(message.chat.id, "Чтобы загрузить новое расписание, просто отправьте фото")
    else:
        bot.send_message(message.chat.id, "У вас нет прав администратора")


@bot.message_handler(content_types=['photo'])
def photo(message):
    if not userIsAdmin(message.from_user.id):
        bot.send_message(message.chat.id, "У вас нет прав администратора")
        return
    fileID = message.photo[-1].file_id
    file_info = bot.get_file(fileID)
    downloaded_file = bot.download_file(file_info.file_path)

    with open(config["replacement_path"]+config["replacement_file_name"], 'wb') as new_file:
        new_file.write(downloaded_file)



bot.infinity_polling()  # делает запуск бота бесконечным
